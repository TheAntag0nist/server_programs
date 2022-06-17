cd ./_server_part/
gnome-terminal -- ./server_app
sleep 1

cd ../_user_part
gnome-terminal -- ./client_app
sleep 1