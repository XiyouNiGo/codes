import frida
import sys

session = frida.attach("onEnter")
script = session.create_script("""
Interceptor.attach(ptr("%s"), {
    onEnter(args) {
        args[0] = ptr("1337");
    }
});
""" % int(sys.argv[1], 16))
script.load()
sys.stdin.read()
