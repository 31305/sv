#!/usr/bin/env python3
import librosa
import sys
import os
s,lg=librosa.load(sys.argv[1])
os.system('mkdir -p /tmp/nvtsl/')
