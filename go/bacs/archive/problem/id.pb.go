// Code generated by protoc-gen-go.
// source: bacs/archive/problem/id.proto
// DO NOT EDIT!

package problem

import proto "github.com/golang/protobuf/proto"
import fmt "fmt"
import math "math"

// Reference imports to suppress errors if they are not otherwise used.
var _ = proto.Marshal
var _ = fmt.Errorf
var _ = math.Inf

type IdSet struct {
	Id []string `protobuf:"bytes,1,rep,name=id" json:"id,omitempty"`
}

func (m *IdSet) Reset()         { *m = IdSet{} }
func (m *IdSet) String() string { return proto.CompactTextString(m) }
func (*IdSet) ProtoMessage()    {}
