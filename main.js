const { app, BrowserWindow } = require('electron')
const path = require('node:path')

// OBS module
const hoyerAddOn = require('./SimpleOBSModule/build/Release/SimpleOBSModule');

const createWindow = () => {
    const win = new BrowserWindow({
        width: 800,
        height: 600,
        webPreferences: {
            preload: path.join(__dirname, 'preload.js')
        }
    })

    //get OBS version and set it as the title of the page
    win.setTitle('OBS version: ' + hoyerAddOn.StartOBS())
    win.loadFile('index.html')
}

app.whenReady().then(() => {
    createWindow()
})

app.on('window-all-closed', () => {
    if (process.platform !== 'darwin') app.quit()
})