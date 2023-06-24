import subprocess
from os import system
s=str(subprocess.check_output('fc-list')).split('\\n')
ln=''
for n in s:
    if n.find('NotoSansBrahmi-Regular')!=-1:
        ln=n.split(':')[0]
        break
system('hb-view -u "1102b 11038 11026 11046 11022 1102f 1102b 11046" --margin="4 4 4 4" --foreground=000000 --background=FFFFFF -o sc.png --font-size 16 '+ln)
