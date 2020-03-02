// Auto-generated. Do not edit!

// (in-package arm.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let coord = require('./coord.js');

//-----------------------------------------------------------

class detector {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.one = null;
      this.two = null;
      this.three = null;
      this.four = null;
      this.object = null;
      this.radius = null;
    }
    else {
      if (initObj.hasOwnProperty('one')) {
        this.one = initObj.one
      }
      else {
        this.one = new coord();
      }
      if (initObj.hasOwnProperty('two')) {
        this.two = initObj.two
      }
      else {
        this.two = new coord();
      }
      if (initObj.hasOwnProperty('three')) {
        this.three = initObj.three
      }
      else {
        this.three = new coord();
      }
      if (initObj.hasOwnProperty('four')) {
        this.four = initObj.four
      }
      else {
        this.four = new coord();
      }
      if (initObj.hasOwnProperty('object')) {
        this.object = initObj.object
      }
      else {
        this.object = new coord();
      }
      if (initObj.hasOwnProperty('radius')) {
        this.radius = initObj.radius
      }
      else {
        this.radius = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type detector
    // Serialize message field [one]
    bufferOffset = coord.serialize(obj.one, buffer, bufferOffset);
    // Serialize message field [two]
    bufferOffset = coord.serialize(obj.two, buffer, bufferOffset);
    // Serialize message field [three]
    bufferOffset = coord.serialize(obj.three, buffer, bufferOffset);
    // Serialize message field [four]
    bufferOffset = coord.serialize(obj.four, buffer, bufferOffset);
    // Serialize message field [object]
    bufferOffset = coord.serialize(obj.object, buffer, bufferOffset);
    // Serialize message field [radius]
    bufferOffset = _serializer.int16(obj.radius, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type detector
    let len;
    let data = new detector(null);
    // Deserialize message field [one]
    data.one = coord.deserialize(buffer, bufferOffset);
    // Deserialize message field [two]
    data.two = coord.deserialize(buffer, bufferOffset);
    // Deserialize message field [three]
    data.three = coord.deserialize(buffer, bufferOffset);
    // Deserialize message field [four]
    data.four = coord.deserialize(buffer, bufferOffset);
    // Deserialize message field [object]
    data.object = coord.deserialize(buffer, bufferOffset);
    // Deserialize message field [radius]
    data.radius = _deserializer.int16(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 42;
  }

  static datatype() {
    // Returns string type for a message object
    return 'arm/detector';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '93aa21638d78edb37fecdca254769315';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    coord one
    coord two
    coord three
    coord four
    coord object
    int16 radius
    
    ================================================================================
    MSG: arm/coord
    int32 x
    int32 y
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new detector(null);
    if (msg.one !== undefined) {
      resolved.one = coord.Resolve(msg.one)
    }
    else {
      resolved.one = new coord()
    }

    if (msg.two !== undefined) {
      resolved.two = coord.Resolve(msg.two)
    }
    else {
      resolved.two = new coord()
    }

    if (msg.three !== undefined) {
      resolved.three = coord.Resolve(msg.three)
    }
    else {
      resolved.three = new coord()
    }

    if (msg.four !== undefined) {
      resolved.four = coord.Resolve(msg.four)
    }
    else {
      resolved.four = new coord()
    }

    if (msg.object !== undefined) {
      resolved.object = coord.Resolve(msg.object)
    }
    else {
      resolved.object = new coord()
    }

    if (msg.radius !== undefined) {
      resolved.radius = msg.radius;
    }
    else {
      resolved.radius = 0
    }

    return resolved;
    }
};

module.exports = detector;
