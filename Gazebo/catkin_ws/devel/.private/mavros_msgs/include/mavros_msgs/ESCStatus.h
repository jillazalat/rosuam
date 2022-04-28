// Generated by gencpp from file mavros_msgs/ESCStatus.msg
// DO NOT EDIT!


#ifndef MAVROS_MSGS_MESSAGE_ESCSTATUS_H
#define MAVROS_MSGS_MESSAGE_ESCSTATUS_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>
#include <mavros_msgs/ESCStatusItem.h>

namespace mavros_msgs
{
template <class ContainerAllocator>
struct ESCStatus_
{
  typedef ESCStatus_<ContainerAllocator> Type;

  ESCStatus_()
    : header()
    , esc_status()  {
    }
  ESCStatus_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , esc_status(_alloc)  {
  (void)_alloc;
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef std::vector< ::mavros_msgs::ESCStatusItem_<ContainerAllocator> , typename ContainerAllocator::template rebind< ::mavros_msgs::ESCStatusItem_<ContainerAllocator> >::other >  _esc_status_type;
  _esc_status_type esc_status;





  typedef boost::shared_ptr< ::mavros_msgs::ESCStatus_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::mavros_msgs::ESCStatus_<ContainerAllocator> const> ConstPtr;

}; // struct ESCStatus_

typedef ::mavros_msgs::ESCStatus_<std::allocator<void> > ESCStatus;

typedef boost::shared_ptr< ::mavros_msgs::ESCStatus > ESCStatusPtr;
typedef boost::shared_ptr< ::mavros_msgs::ESCStatus const> ESCStatusConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::mavros_msgs::ESCStatus_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::mavros_msgs::ESCStatus_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::mavros_msgs::ESCStatus_<ContainerAllocator1> & lhs, const ::mavros_msgs::ESCStatus_<ContainerAllocator2> & rhs)
{
  return lhs.header == rhs.header &&
    lhs.esc_status == rhs.esc_status;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::mavros_msgs::ESCStatus_<ContainerAllocator1> & lhs, const ::mavros_msgs::ESCStatus_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace mavros_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::mavros_msgs::ESCStatus_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::mavros_msgs::ESCStatus_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::mavros_msgs::ESCStatus_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::mavros_msgs::ESCStatus_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::mavros_msgs::ESCStatus_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::mavros_msgs::ESCStatus_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::mavros_msgs::ESCStatus_<ContainerAllocator> >
{
  static const char* value()
  {
    return "145d49eaf5cfecbdfd50ae4a22fe82d4";
  }

  static const char* value(const ::mavros_msgs::ESCStatus_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x145d49eaf5cfecbdULL;
  static const uint64_t static_value2 = 0xfd50ae4a22fe82d4ULL;
};

template<class ContainerAllocator>
struct DataType< ::mavros_msgs::ESCStatus_<ContainerAllocator> >
{
  static const char* value()
  {
    return "mavros_msgs/ESCStatus";
  }

  static const char* value(const ::mavros_msgs::ESCStatus_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::mavros_msgs::ESCStatus_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# ESCStatus.msg\n"
"#\n"
"#\n"
"# See mavlink message documentation here:\n"
"# https://mavlink.io/en/messages/common.html#ESC_STATUS\n"
"\n"
"std_msgs/Header header\n"
"\n"
"mavros_msgs/ESCStatusItem[] esc_status\n"
"\n"
"================================================================================\n"
"MSG: std_msgs/Header\n"
"# Standard metadata for higher-level stamped data types.\n"
"# This is generally used to communicate timestamped data \n"
"# in a particular coordinate frame.\n"
"# \n"
"# sequence ID: consecutively increasing ID \n"
"uint32 seq\n"
"#Two-integer timestamp that is expressed as:\n"
"# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')\n"
"# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')\n"
"# time-handling sugar is provided by the client library\n"
"time stamp\n"
"#Frame this data is associated with\n"
"string frame_id\n"
"\n"
"================================================================================\n"
"MSG: mavros_msgs/ESCStatusItem\n"
"# ESCStatusItem.msg\n"
"#\n"
"#\n"
"# See mavlink message documentation here:\n"
"# https://mavlink.io/en/messages/common.html#ESC_STATUS\n"
"\n"
"std_msgs/Header header\n"
"\n"
"int32 rpm\n"
"float32 voltage\n"
"float32 current\n"
;
  }

  static const char* value(const ::mavros_msgs::ESCStatus_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::mavros_msgs::ESCStatus_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.esc_status);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct ESCStatus_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::mavros_msgs::ESCStatus_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::mavros_msgs::ESCStatus_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "esc_status[]" << std::endl;
    for (size_t i = 0; i < v.esc_status.size(); ++i)
    {
      s << indent << "  esc_status[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::mavros_msgs::ESCStatusItem_<ContainerAllocator> >::stream(s, indent + "    ", v.esc_status[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // MAVROS_MSGS_MESSAGE_ESCSTATUS_H
