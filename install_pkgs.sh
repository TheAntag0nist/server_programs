if ! make -v > /dev/null
then
    echo "make could not be found"
    sudo apt install make
else
    echo "make was found"
fi

if ! g++ --version > /dev/null
then
    echo "g++ could not be found"
    sudo apt install g++
else
    echo "g++ was found"
fi