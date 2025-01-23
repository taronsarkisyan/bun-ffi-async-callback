#!/usr/bin/env bun

/** @ts-ignore */
import { dlopen, CString, JSCallback, FFIType } from "bun:ffi";
import path from "path";

const libPath = path.resolve(__dirname, "./bin/index.so");
const { symbols } = dlopen(libPath, {
  create: {
    args: [],
    returns: FFIType.void,
  },
  setCallback: {
    args: [FFIType.function],
    returns: FFIType.void,
  },
  runCallback: {
    args: [],
    returns: FFIType.void
  }
});

symbols.create();

const callbackWrapper = async (message: string) => {
  console.log(`[Bun]: ${message}`);
  return message;
};

const cHandler = new JSCallback(
  (cMessage: any) => {
    const message: string = new CString(cMessage);
    return callbackWrapper(message)
      .then((response: string) => Buffer.from(response, "utf-8"));
  },
  {
    returns: "cstring",
    args: [FFIType.ptr],
  },
);

symbols.setCallback(cHandler);
symbols.runCallback();