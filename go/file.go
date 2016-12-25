package main

import (
	"fmt"
	"os"
)

const FileName = "filename"
const OffSet = 64

func write() error {

	file, err := os.OpenFile(FileName, os.O_CREATE|os.O_RDWR, 0660)
	if err != nil {
		return err
	}

	data := []byte("12345")
	file.WriteAt(data, OffSet)

	return nil
}

func read() (string, error) {

	file, err := os.OpenFile(FileName, os.O_CREATE|os.O_RDWR, 0660)
	if err != nil {
		return "", err
	}

	buffer := make([]byte, 5)
	file.ReadAt(buffer, OffSet)

	return string(buffer), nil
}

func main() {
	err := write()
	if err != nil {
		fmt.Println(err)
	}
	s, err := read()
	if err != nil {
		fmt.Println(err)
	}
	fmt.Println(s)
}
