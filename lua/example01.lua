aloha.init()
config = aloha.create_config()
flags = aloha.WINDOWED | aloha.OPENGL_3_0
aloha.set_new_display_flags(flags)
display = aloha.create_display(1024, 768)
if display == nil then
    print('Nil disp')
else
    print('Ok')
end
f = aloha.get_new_display_flags()
print(f)
aloha.destroy_display(display)
aloha.destroy_config(config)
aloha.uninstall_system()
