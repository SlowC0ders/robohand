// Auto-generated. Do not edit!

// (in-package arm.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class angles {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.shoulder = null;
      this.elbow = null;
      this.wrist = null;
    }
    else {
      if (initObj.hasOwnProperty('shoulder')) {
        this.shoulder = initObj.shoulder
      }
      else {
        this.shoulder = 0;
      }
      if (initObj.hasOwnProperty('elbow')) {
        this.elbow = initObj.elbow
      }
      else {
        this.elbow = 0;
      }
      if (initObj.hasOwnProperty('wrist')) {
        this.wrist = initObj.wrist
      }
      else {
        this.wrist = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type angles
    // Serialize message field [shoulder]
    bufferOffset = _serializer.uint16(obj.shoulder, buffer, bufferOffset);
    // Serialize message field [elbow]
    bufferOffset = _serializer.uint16(obj.elbow, buffer, bufferOffset);
    // Serialize message field [wrist]
    bufferOffset = _serializer.uint16(obj.wrist, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type angles
    let len;
    let data = new angles(null);
    // Deserialize message field [shoulder]
    data.shoulder = _deserializer.uint16(buffer, bufferOffset);
    // Deserialize message field [elbow]
    data.elbow = _deserializer.uint16(buffer, bufferOffset);
    // Deserialize message field [wrist]
    data.wrist = _deserializer.uint16(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 6;
  }

  static datatype() {
    // Returns string type for a message object
    return 'arm/angles';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '8960ce5da37f48308cf296b103d3ad7f';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    uint16 shoulder
    uint16 elbow
    uint16 wrist
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new angles(null);
    if (msg.shoulder !== undefined) {
      resolved.shoulder = msg.shoulder;
    }
    else {
      resolved.shoulder = 0
    }

    if (msg.elbow !== undefined) {
      resolved.elbow = msg.elbow;
    }
    else {
      resolved.elbow = 0
    }

    if (msg.wrist !== undefined) {
      resolved.wrist = msg.wrist;
    }
    else {
      resolved.wrist = 0
    }

    return resolved;
    }
};

module.exports = angles;
