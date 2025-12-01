import std.stdio, std.file, std.conv, std.string;

void main()
{
    string file_path = "./example.txt";
    auto lines = readText(file_path).strip().splitLines();
    
    int currentCode = 50;
    int num_of_zeros = 0;
    
    foreach(line; lines) {
        if (line.length < 2) continue;
        
        char letter = line[0];
        string numbers = line[1..$];  
        
        int num = numbers.to!int;
        
        if (letter == 'L') {
            for (int i = 1; i <= num; i++) {
                int checkCode = (currentCode - i) % 100;
                if (checkCode < 0) checkCode += 100;
                if (checkCode == 0) {
                    num_of_zeros++;
                }
            }
            
            currentCode = (currentCode - num) % 100;
            if (currentCode < 0) {
                currentCode += 100;
            }
        }
        else if (letter == 'R') {
            for (int i = 1; i <= num; i++) {
                int checkCode = (currentCode + i) % 100;
                if (checkCode == 0) {
                    num_of_zeros++;
                }
            }
            
            currentCode = (currentCode + num) % 100;
        }
       
    }
    
    writeln("Dial pointed to zero:", num_of_zeros, "many times");
}