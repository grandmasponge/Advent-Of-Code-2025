#!/usr/bin/env ruby

def main
  file_path = "input.txt"
  file = File.open(file_path)
  lines = file.readlines.map(&:chomp)
  
  width = lines[0].length
  height = lines.length
  
  puts "Width: #{width}, Height: #{height}"
  

  start_col = nil
  lines[0].chars.each_with_index do |char, idx|
    if char == 'S'
      start_col = idx
      break
    end
  end
  

  current_row = Array.new(width, 0)
  current_row[start_col] = 1
  

  (1...height).each do |row|
    next_row = Array.new(width, 0)
    
   
    width.times do |col|
      next if current_row[col] == 0
      
      char = lines[row][col]
      
      if char == '.' || char == 'S'
      
        next_row[col] += current_row[col]
      elsif char == '^'
 
        if col > 0 && lines[row][col - 1] == '.'
          next_row[col - 1] += current_row[col]
        end
        if col < width - 1 && lines[row][col + 1] == '.'
          next_row[col + 1] += current_row[col]
        end
      end
    end
    
    current_row = next_row
    
  end

  total_timelines = current_row.sum
  
  puts "Total timelines: #{total_timelines}"
  

  puts "\nBottom row timeline distribution:"
  current_row.each_with_index do |count, idx|
    if count > 0
      puts "  Column #{idx}: #{count} timelines"
    end
  end
end

main