package main

import (
	"fmt"
	"os"
	"strings"
)

const file_path = "input.txt"

func hasRoll(x int, y int, matrix [][] string) bool{
    if (matrix[y][x] == "@") {
        return true
    }
    return false
}

func checkAround(x int, y int, width int, height int, matrix [][]string) bool {

    var check_left = false
    var check_right = false

    var touching = 0

    if ((x - 1) >= 0) {
        check_left = true
    }

    if ((x + 1) <= (width -1)) {
        check_right = true
    }
    
    
    if ((y-1) >= 0) {

        //above left
        if (check_left) {
            if (hasRoll(x -1, y-1, matrix)) {
                touching++
            }
        }
        //above

        if (hasRoll(x, y-1, matrix)) {
            touching++
        }

        //above right
        if (check_right) {
            if (hasRoll(x + 1, y - 1, matrix)) {
                touching++
            }
        }
        
    } 

    // left
    if (check_left) {
        if (hasRoll(x -1, y, matrix)) {
            touching++
        }
    }

    // right
    if(check_right) {
        if (hasRoll(x + 1, y, matrix)) {
            touching++
        }
    }

    if ((y +1) <= height - 1)  {

        //below left
        if (check_left) {
            if (hasRoll(x -1, y+1, matrix)) {
                touching++
            }
        }

        //below
        if (hasRoll(x, y+1, matrix)) {
            touching++
        }

        //below right
        if (check_right) {
            if (hasRoll(x + 1, y + 1, matrix)) {
                touching++
            }
        }

    }


    if (touching >= 4) {
        return false
    }

    return true
}

func main() {
  
    data, err := os.ReadFile(file_path)

    var matrix [][] string

    if (err != nil) {
        fmt.Println("[ERROR] failed to read file at path: ", file_path)
        os.Exit(-1);
    }

    var string_data string = string(data)

    lines := strings.Split(strings.TrimSpace(string_data), "\n")

    for _, line := range lines {
        row := strings.Split(line, "")
        matrix = append(matrix, row)
    }

    var width, height int
    

     if len(matrix) > 0 && len(matrix[0]) > 0 {
        height = len(matrix)
        width = len(matrix[0])
        fmt.Printf("Width: %d, Height: %d\n", width, height)
    }

    var total = 0
    var removed = 1

    for removed != 0 {
        removed = 0

        for i:=0; i < len(matrix); i++ {
        var y int = i // just so i can visualise it better i use x and y  but for for loops its wrong not to use i. and j it feels wrong
        for j := 0; j < len(matrix[0]); j++ {
            var x int = j
            if (matrix[y][x] == ".") {
                continue
            }
            if (checkAround(x, y, width, height, matrix)) {
                matrix[y][x] = "."
                total++
                removed = 1
            }
        }
    }
    }   

    fmt.Println(total)
    os.Exit(0)
}