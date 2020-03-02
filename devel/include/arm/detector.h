// Generated by gencpp from file arm/detector.msg
// DO NOT EDIT!


#ifndef ARM_MESSAGE_DETECTOR_H
#define ARM_MESSAGE_DETECTOR_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <arm/coord.h>
#include <arm/coord.h>
#include <arm/coord.h>
#include <arm/coord.h>
#include <arm/coord.h>

namespace arm
{
template <class ContainerAllocator>
struct detector_
{
  typedef detector_<ContainerAllocator> Type;

  detector_()
    : one()
    , two()
    , three()
    , four()
    , object()
    , radius(0)  {
    }
  detector_(const ContainerAllocator& _alloc)
    : one(_alloc)
    , two(_alloc)
    , three(_alloc)
    , four(_alloc)
    , object(_alloc)
    , radius(0)  {
  (void)_alloc;
    }



   typedef  ::arm::coord_<ContainerAllocator>  _one_type;
  _one_type one;

   typedef  ::arm::coord_<ContainerAllocator>  _two_type;
  _two_type two;

   typedef  ::arm::coord_<ContainerAllocator>  _three_type;
  _three_type three;

   typedef  ::arm::coord_<ContainerAllocator>  _four_type;
  _four_type four;

   typedef  ::arm::coord_<ContainerAllocator>  _object_type;
  _object_type object;

   typedef int16_t _radius_type;
  _radius_type radius;





  typedef boost::shared_ptr< ::arm::detector_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::arm::detector_<ContainerAllocator> const> ConstPtr;

}; // struct detector_

typedef ::arm::detector_<std::allocator<void> > detector;

typedef boost::shared_ptr< ::arm::detector > detectorPtr;
typedef boost::shared_ptr< ::arm::detector const> detectorConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::arm::detector_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::arm::detector_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace arm

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/melodic/share/std_msgs/cmake/../msg'], 'arm': ['/home/johnnyname/arm_ws/src/arm/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::arm::detector_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::arm::detector_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::arm::detector_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::arm::detector_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::arm::detector_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::arm::detector_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::arm::detector_<ContainerAllocator> >
{
  static const char* value()
  {
    return "93aa21638d78edb37fecdca254769315";
  }

  static const char* value(const ::arm::detector_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x93aa21638d78edb3ULL;
  static const uint64_t static_value2 = 0x7fecdca254769315ULL;
};

template<class ContainerAllocator>
struct DataType< ::arm::detector_<ContainerAllocator> >
{
  static const char* value()
  {
    return "arm/detector";
  }

  static const char* value(const ::arm::detector_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::arm::detector_<ContainerAllocator> >
{
  static const char* value()
  {
    return "coord one\n"
"coord two\n"
"coord three\n"
"coord four\n"
"coord object\n"
"int16 radius\n"
"\n"
"================================================================================\n"
"MSG: arm/coord\n"
"int32 x\n"
"int32 y\n"
;
  }

  static const char* value(const ::arm::detector_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::arm::detector_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.one);
      stream.next(m.two);
      stream.next(m.three);
      stream.next(m.four);
      stream.next(m.object);
      stream.next(m.radius);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct detector_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::arm::detector_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::arm::detector_<ContainerAllocator>& v)
  {
    s << indent << "one: ";
    s << std::endl;
    Printer< ::arm::coord_<ContainerAllocator> >::stream(s, indent + "  ", v.one);
    s << indent << "two: ";
    s << std::endl;
    Printer< ::arm::coord_<ContainerAllocator> >::stream(s, indent + "  ", v.two);
    s << indent << "three: ";
    s << std::endl;
    Printer< ::arm::coord_<ContainerAllocator> >::stream(s, indent + "  ", v.three);
    s << indent << "four: ";
    s << std::endl;
    Printer< ::arm::coord_<ContainerAllocator> >::stream(s, indent + "  ", v.four);
    s << indent << "object: ";
    s << std::endl;
    Printer< ::arm::coord_<ContainerAllocator> >::stream(s, indent + "  ", v.object);
    s << indent << "radius: ";
    Printer<int16_t>::stream(s, indent + "  ", v.radius);
  }
};

} // namespace message_operations
} // namespace ros

#endif // ARM_MESSAGE_DETECTOR_H
