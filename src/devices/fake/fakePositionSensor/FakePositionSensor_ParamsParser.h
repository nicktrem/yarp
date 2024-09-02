/*
 * SPDX-FileCopyrightText: 2023-2023 Istituto Italiano di Tecnologia (IIT)
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */


// Generated by yarpDeviceParamParserGenerator (1.0)
// This is an automatically generated file. Please do not edit it.
// It will be re-generated if the cmake flag ALLOW_DEVICE_PARAM_PARSER_GERNERATION is ON.

// Generated on: Thu Mar  7 17:59:42 2024


#ifndef FAKEPOSITIONSENSOR_PARAMSPARSER_H
#define FAKEPOSITIONSENSOR_PARAMSPARSER_H

#include <yarp/os/Searchable.h>
#include <yarp/dev/IDeviceDriverParams.h>
#include <string>
#include <cmath>

/**
* This class is the parameters parser for class FakePositionSensor.
*
* These are the used parameters:
* | Group name | Parameter name | Type   | Units | Default Value | Required | Description   | Notes                  |
* |:----------:|:--------------:|:------:|:-----:|:-------------:|:--------:|:-------------:|:----------------------:|
* | -          | period         | double | s     | 0.01          | 0        | thread period | optional, default 1.0s |
*
* The device can be launched by yarpdev using one of the following examples (with and without all optional parameters):
* \code{.unparsed}
* yarpdev --device fakePositionSensor --period 0.01
* \endcode
*
* \code{.unparsed}
* yarpdev --device fakePositionSensor
* \endcode
*
*/

class FakePositionSensor_ParamsParser : public yarp::dev::IDeviceDriverParams
{
public:
    FakePositionSensor_ParamsParser();
    ~FakePositionSensor_ParamsParser() override = default;

public:
    const std::string m_device_classname = {"FakePositionSensor"};
    const std::string m_device_name = {"fakePositionSensor"};
    bool m_parser_is_strict = false;
    struct parser_version_type
    {
         int major = 1;
         int minor = 0;
    };
    const parser_version_type m_parser_version = {};

    const std::string m_period_defaultValue = {"0.01"};

    double m_period = {0.01};

    bool          parseParams(const yarp::os::Searchable & config) override;
    std::string   getDeviceClassName() const override { return m_device_classname; }
    std::string   getDeviceName() const override { return m_device_name; }
    std::string   getDocumentationOfDeviceParams() const override;
    std::vector<std::string> getListOfParams() const override;
};

#endif