
"use strict";

let FileRead = require('./FileRead.js')
let FileOpen = require('./FileOpen.js')
let FileWrite = require('./FileWrite.js')
let FileRename = require('./FileRename.js')
let StreamRate = require('./StreamRate.js')
let VehicleInfoGet = require('./VehicleInfoGet.js')
let SetMavFrame = require('./SetMavFrame.js')
let CommandBool = require('./CommandBool.js')
let CommandInt = require('./CommandInt.js')
let CommandLong = require('./CommandLong.js')
let FileClose = require('./FileClose.js')
let CommandVtolTransition = require('./CommandVtolTransition.js')
let CommandTOL = require('./CommandTOL.js')
let LogRequestData = require('./LogRequestData.js')
let CommandTriggerControl = require('./CommandTriggerControl.js')
let ParamGet = require('./ParamGet.js')
let WaypointClear = require('./WaypointClear.js')
let FileList = require('./FileList.js')
let CommandTriggerInterval = require('./CommandTriggerInterval.js')
let LogRequestList = require('./LogRequestList.js')
let ParamPush = require('./ParamPush.js')
let WaypointPush = require('./WaypointPush.js')
let WaypointSetCurrent = require('./WaypointSetCurrent.js')
let CommandAck = require('./CommandAck.js')
let MountConfigure = require('./MountConfigure.js')
let ParamPull = require('./ParamPull.js')
let SetMode = require('./SetMode.js')
let LogRequestEnd = require('./LogRequestEnd.js')
let CommandHome = require('./CommandHome.js')
let WaypointPull = require('./WaypointPull.js')
let FileMakeDir = require('./FileMakeDir.js')
let FileTruncate = require('./FileTruncate.js')
let MessageInterval = require('./MessageInterval.js')
let FileRemoveDir = require('./FileRemoveDir.js')
let ParamSet = require('./ParamSet.js')
let FileChecksum = require('./FileChecksum.js')
let FileRemove = require('./FileRemove.js')

module.exports = {
  FileRead: FileRead,
  FileOpen: FileOpen,
  FileWrite: FileWrite,
  FileRename: FileRename,
  StreamRate: StreamRate,
  VehicleInfoGet: VehicleInfoGet,
  SetMavFrame: SetMavFrame,
  CommandBool: CommandBool,
  CommandInt: CommandInt,
  CommandLong: CommandLong,
  FileClose: FileClose,
  CommandVtolTransition: CommandVtolTransition,
  CommandTOL: CommandTOL,
  LogRequestData: LogRequestData,
  CommandTriggerControl: CommandTriggerControl,
  ParamGet: ParamGet,
  WaypointClear: WaypointClear,
  FileList: FileList,
  CommandTriggerInterval: CommandTriggerInterval,
  LogRequestList: LogRequestList,
  ParamPush: ParamPush,
  WaypointPush: WaypointPush,
  WaypointSetCurrent: WaypointSetCurrent,
  CommandAck: CommandAck,
  MountConfigure: MountConfigure,
  ParamPull: ParamPull,
  SetMode: SetMode,
  LogRequestEnd: LogRequestEnd,
  CommandHome: CommandHome,
  WaypointPull: WaypointPull,
  FileMakeDir: FileMakeDir,
  FileTruncate: FileTruncate,
  MessageInterval: MessageInterval,
  FileRemoveDir: FileRemoveDir,
  ParamSet: ParamSet,
  FileChecksum: FileChecksum,
  FileRemove: FileRemove,
};
