if (typeof window == 'undefined') {
  // worker thread, preload the JSMESSLoader definition file
  importScripts('JSMESSLoader.js');
}

var JSMESS = new JSMESSLoader({ 
  webroot: '/media/vrcade/games/SYSTEM/',
  useWebGL: false,
  useWorker: false,
  useSound: true,
  systemname: 'messSYSTEM',
  gamename: 'GAME_FILE',
  bios_filenames: 'BIOS_FILES'.split(' '),
  messargs: MESS_ARGS
});
