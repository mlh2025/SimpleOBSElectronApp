SimpleOBSModule: Node.js native add on module to load OBS and return the version to the Electron app
  *binding.gyp include dir is hard coded - needs to be updated to the location of obs-studio/libobs
  npm install node-addon-api
  node-gyp configure
  node-gyp build

SimpleElectronApp: loads SimpleOBSModule and displays the OBS version as the title of the window
  npm install electron
  npm start

