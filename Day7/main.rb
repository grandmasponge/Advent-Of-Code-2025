#!/usr/bin/env ruby



def main
  file_path = "input.txt"
  file = File.open(file_path)
  lines = file.readlines.map(&:chomp)

  width = lines[0].length
  height = lines.length
  puts "width: #{width}, Height: #{height}"
  split = 0
  
  for i in 1..height -1
    ab = i - 1
    line = lines[i]
    for j in 0..width -1
        char = line[j]
        if char == "."
            if lines[ab][j] == "S" || lines[ab][j] == "|"
                line[j] = "|"
            end
        elsif char == "^"
            if lines[ab][j] == "|"
                split = split + 1
                line[j-1] = "|"
                line[j+1] = "|"
            end
        end
    end
  end
  puts lines
  puts "Split: #{split}"
  
end

main
