#!/bin/bash

ls | egrep '\.flac$|\.wav$|\.ogg$|\.mka$|\.webm$|\.m4a$|\.mp3$|\.mkv$|\.mp4$' > ".mpv-pl-list"

mpv -playlist=".mpv-pl-list"
rm ".mpv-pl-list"
