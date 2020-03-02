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

class converter {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.object = null;
    }
    else {
      if (initObj.hasOwnProperty('object')) {
        this.object = initObj.object
      }
      else {
        this.object = new coord();
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type converter
    // Serialize message field [object]
    bufferOffset = coord.serialize(obj.object, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type converter
    let len;
    let data = new converter(null);
    // Deserialize message field [object]
    data.object = coord.deserialize(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 8;
  }

  static datatype() {
    // Returns string type for a message object
    return 'arm/converter';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '1431af4482a444b26905122d6a7f3716';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    coord object
    
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
    const resolved = new converter(null);
    if (msg.object !== undefined) {
      resolved.object = coord.Resolve(msg.object)
    }
    else {
      resolved.object = new coord()
    }

    return resolved;
    }
};

module.exports = converter;
