#include <boost/program_options.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/info_parser.hpp>

#include "bunsan/util.hpp"

#include "bacs/archive/repository.hpp"

int main(int argc, char **argv)
{
    std::string config_file;
    std::string format;
    bacs::archive::problem::archive_format archive_format;
    std::string input, output;
    try
    {
        //command line parser
        boost::program_options::options_description desc(argv[0]);
        desc.add_options()
            ("help,h", "Print this information")
            ("version,V", "Program version")
            ("config,c", boost::program_options::value<std::string>(&config_file))
            ("format,f", boost::program_options::value<std::string>(&format))
            ("input,i", boost::program_options::value<std::string>(&input))
            ("output,i", boost::program_options::value<std::string>(&output))
            ("insert", "Insert problem from directory")
            ("insert_all", "Insert all problems from archive");
        boost::program_options::variables_map vm;
        boost::program_options::store(boost::program_options::parse_command_line(argc, argv, desc), vm);
        boost::program_options::notify(vm);
        if (vm.count("help"))
        {
            std::cerr<<desc<<std::endl;
            return 1;
        }
        if (vm.count("version"))
        {
            std::cerr<<"It is too early to announce project version"<<std::endl;
            return 1;
        }
        DLOG(config parse);
        boost::property_tree::ptree config;
        bunsan::read_info(config_file, config);
        bacs::archive::repository repo(config);
        {
            const std::string::size_type pos = format.find(':');
            bacs::archive::problem::archive_format archive_format;
            archive_format.archiver = format.substr(pos);
            if (pos!=std::string::npos)
                archive_format.format = format.substr(pos+1);
        }
        if (vm.count("insert_all"))
        {
            bacs::archive::problem::import_map map = repo.insert_all(archive_format, input);
            // TODO import_map output
        }
        else if (vm.count("insert"))
        {
            boost::filesystem::path path = boost::filesystem::absolute(input);
            bacs::archive::problem::import_info info = repo.insert(path.filename().string(), path);
            // TODO info output
        }
        else if (vm.count("extract"))
        {
        }
        else if (vm.count("info"))
        {
        }
        else if (vm.count("hash"))
        {
        }
    }
    catch (std::exception &e)
    {
        DLOG(Oops! An exception has occured);
        std::cerr<<e.what()<<std::endl;
        return 200;
    }
}
