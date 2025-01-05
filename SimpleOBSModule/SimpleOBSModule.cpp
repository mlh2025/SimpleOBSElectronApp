//node_addon_api
#include <napi.h>

//obs 
#include "./libobs/obs.h"

//OBS calls
static Napi::String StartOBS(const Napi::CallbackInfo& info) 
{
    // Napi::Env is the opaque data structure containing the environment in which
    // the request is being run. We will need this env when we want to create any
    // new objects inside of the node.js environment
    Napi::Env env = info.Env();

    // Create a C++ level variable
    std::string retString = "";
    
    //OBS initialization
    const char* curLocale = "en - US";
        
    if (!obs_startup("en - US", NULL, NULL))
        //if (!obs_startup(curLocale, NULL, NULL))
    {
        retString = "obs_startup failure";
    }
    else
    {
        retString = obs_get_version_string();
    }

    //got the version, now shut it down
    obs_shutdown();

    // Return a new javascript string that we copy-construct inside of the node.js
    // environment
    return Napi::String::New(env, retString);
}


static Napi::Object Init(Napi::Env env, Napi::Object exports)
{
    //setup functions
    exports.Set(Napi::String::New(env, "StartOBS"),
        Napi::Function::New(env, StartOBS));

    return exports;
}

NODE_API_MODULE(NODE_GYP_MODULE_NAME, Init)
