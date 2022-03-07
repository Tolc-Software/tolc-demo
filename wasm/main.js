// A javascript file that
// uses the C++ library MyCppLib
const loadMyCppLib = require('./MyCppLib');

// WebAssembly is loaded asynchronous
// via a Promise
loadMyCppLib().then(MyCppLib => {
	console.log(MyCppLib.Hello.cppFunction('friend'));
});
