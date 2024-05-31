# OTF - ONNX to FPGA - a flow for generating hardware based on ONNX models using TVM

This project is the product of a special course at DTU focusing on compilation of machine learning models to hardware. It was done in collaboration with DTU Compute.

## Introduction

This repository contains and explains a flow that was devoloped for compiling machine learning models, from ONNX to FPGA, using [TVM](https://github.com/apache/tvm) and Vitis HLS.

### Requirements

This flow requires a local [TVM](https://github.com/apache/tvm) installation and Vitis HLS, only the newest version at todays date 21/05/2024, has been tested.

## Running the flow

The project contains a jupyter notebook that has all the necesarry steps to compile, synthesise and run and onnx model.

## Disclaimer / TODO

The current version of the C file clean up scirpts in `cleanup.py` is not yet able to fully prepare for HLS. There is therfore still some manual work required there, though this is explained in the flow.