#include "bacs/archive/web/content/form/list_query.hpp"

namespace bacs{namespace archive{namespace web{namespace content{namespace form
{
    list_query::list_query()
    {
        ids.message(cppcms::locale::translate("Problem ids"));
        add(ids);
        add(submit);
    }

    list_query::list_query(const std::string &query): list_query()
    {
        submit.value(query);
    }
}}}}}