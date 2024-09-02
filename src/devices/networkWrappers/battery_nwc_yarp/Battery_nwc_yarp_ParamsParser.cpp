/*
 * SPDX-FileCopyrightText: 2023-2023 Istituto Italiano di Tecnologia (IIT)
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */


// Generated by yarpDeviceParamParserGenerator (1.0)
// This is an automatically generated file. Please do not edit it.
// It will be re-generated if the cmake flag ALLOW_DEVICE_PARAM_PARSER_GERNERATION is ON.

// Generated on: Thu Mar  7 17:59:44 2024


#include "Battery_nwc_yarp_ParamsParser.h"
#include <yarp/os/LogStream.h>
#include <yarp/os/Value.h>

namespace {
    YARP_LOG_COMPONENT(Battery_nwc_yarpParamsCOMPONENT, "yarp.device.Battery_nwc_yarp")
}


Battery_nwc_yarp_ParamsParser::Battery_nwc_yarp_ParamsParser()
{
}


std::vector<std::string> Battery_nwc_yarp_ParamsParser::getListOfParams() const
{
    std::vector<std::string> params;
    params.push_back("local");
    params.push_back("remote");
    params.push_back("carrier");
    return params;
}


bool      Battery_nwc_yarp_ParamsParser::parseParams(const yarp::os::Searchable & config)
{
    //Check for --help option
    if (config.check("help"))
    {
        yCInfo(Battery_nwc_yarpParamsCOMPONENT) << getDocumentationOfDeviceParams();
    }

    std::string config_string = config.toString();
    yarp::os::Property prop_check(config_string.c_str());
    //Parser of parameter local
    {
        if (config.check("local"))
        {
            m_local = config.find("local").asString();
            yCInfo(Battery_nwc_yarpParamsCOMPONENT) << "Parameter 'local' using value:" << m_local;
        }
        else
        {
            yCError(Battery_nwc_yarpParamsCOMPONENT) << "Mandatory parameter 'local' not found!";
            yCError(Battery_nwc_yarpParamsCOMPONENT) << "Description of the parameter: Full port name opened by the batteryClient device.";
            return false;
        }
        prop_check.unput("local");
    }

    //Parser of parameter remote
    {
        if (config.check("remote"))
        {
            m_remote = config.find("remote").asString();
            yCInfo(Battery_nwc_yarpParamsCOMPONENT) << "Parameter 'remote' using value:" << m_remote;
        }
        else
        {
            yCError(Battery_nwc_yarpParamsCOMPONENT) << "Mandatory parameter 'remote' not found!";
            yCError(Battery_nwc_yarpParamsCOMPONENT) << "Description of the parameter: Full port name of the port opened on the server side, to which the batteryClient connects to.";
            return false;
        }
        prop_check.unput("remote");
    }

    //Parser of parameter carrier
    {
        if (config.check("carrier"))
        {
            m_carrier = config.find("carrier").asString();
            yCInfo(Battery_nwc_yarpParamsCOMPONENT) << "Parameter 'carrier' using value:" << m_carrier;
        }
        else
        {
            yCInfo(Battery_nwc_yarpParamsCOMPONENT) << "Parameter 'carrier' using DEFAULT value:" << m_carrier;
        }
        prop_check.unput("carrier");
    }

    /*
    //This code check if the user set some parameter which are not check by the parser
    //If the parser is set in strict mode, this will generate an error
    if (prop_check.size() > 0)
    {
        bool extra_params_found = false;
        for (auto it=prop_check.begin(); it!=prop_check.end(); it++)
        {
            if (m_parser_is_strict)
            {
                yCError(Battery_nwc_yarpParamsCOMPONENT) << "User asking for parameter: "<<it->name <<" which is unknown to this parser!";
                extra_params_found = true;
            }
            else
            {
                yCWarning(Battery_nwc_yarpParamsCOMPONENT) << "User asking for parameter: "<< it->name <<" which is unknown to this parser!";
            }
        }

       if (m_parser_is_strict && extra_params_found)
       {
           return false;
       }
    }
    */
    return true;
}


std::string      Battery_nwc_yarp_ParamsParser::getDocumentationOfDeviceParams() const
{
    std::string doc;
    doc = doc + std::string("\n=============================================\n");
    doc = doc + std::string("This is the help for device: Battery_nwc_yarp\n");
    doc = doc + std::string("\n");
    doc = doc + std::string("This is the list of the parameters accepted by the device:\n");
    doc = doc + std::string("'local': Full port name opened by the batteryClient device.\n");
    doc = doc + std::string("'remote': Full port name of the port opened on the server side, to which the batteryClient connects to.\n");
    doc = doc + std::string("'carrier': The carrier used for the connection with the server.\n");
    doc = doc + std::string("\n");
    doc = doc + std::string("Here are some examples of invocation command with yarpdev, with all params:\n");
    doc = doc + " yarpdev --device battery_nwc_yarp --local <mandatory_value> --remote <mandatory_value> --carrier tcp\n";
    doc = doc + std::string("Using only mandatory params:\n");
    doc = doc + " yarpdev --device battery_nwc_yarp --local <mandatory_value> --remote <mandatory_value>\n";
    doc = doc + std::string("=============================================\n\n");    return doc;
}