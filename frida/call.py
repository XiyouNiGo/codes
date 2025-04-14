import frida
import sys

session = frida.attach("onEnter")
script = session.create_script("""
const f = new NativeFunction(ptr("%s"), 'void', ['int']);
f(1911);
f(1911);
f(1911);
""" % int(sys.argv[1], 16))
script.load()
