{
	"targets": [
		{
		"target_name": "SimpleOBSModule",
		"sources" : ["SimpleOBSModule.cpp"],
		"include_dirs": ["<!@(node -p \"require('node-addon-api').include\")",
		"C:/Users/Gary/source/repos/HoyerStreamlabsCodingAssignment/obs-studio/libobs/"	],
	"link_settings": 
		{
		"libraries": ["-lobs.lib"],
		"library_dirs": [
          "<(module_root_dir)/libs"]
		},

		'defines': ['NAPI_DISABLE_CPP_EXCEPTIONS'],
				"copies": [
        {
        "destination": "<(module_root_dir)/build/Release/",
            "files": ["./libs/obs.dll",
					  "./libs/zlib.dll",
					  "./libs/w32-pthreads.dll"]
		}
            ]

        },
    ]
}