use std::{fs::File, io::Read};


#[derive(Debug, Clone)]
pub struct Ranges {
    pub low: i64,
    pub high: i64,
}

impl Ranges {
    fn new(low: i64, high: i64) -> Self {
        Self {
            low,
            high
        }
    }

    fn within_range(&self, num: i64) -> bool {
        num >= self.low && num <= self.high
    }
}

pub enum Mode {
    Ranges,
    Ids,
}

const FILE_PATH: &str = "input.txt";


fn main() {
    
    let file_result: std::io::Result<File> = File::open(FILE_PATH);

   let mut file=  match file_result {
        Ok(file) => file,
        Err(_e) => {
            panic!("[Error] Failed to open file: {}", FILE_PATH);
        }
    };

    let mut contents = String::new();
    match file.read_to_string(&mut contents){
        Ok(_size) => {},
        Err(_e) => {
            panic!("[Error] failed to read from file")
        }
    }

    let lines: Vec<_> = contents
    .split("\n")
    .collect();

    let mut ranges: Vec<Ranges> = Vec::new();
    let mut ids: Vec<i64> = Vec::new();

    let mut mode = Mode::Ranges;

    for line in lines {
        if line.is_empty() {
            break;
            
        }

        match mode {
            Mode::Ranges => {
                ranges.push(parse_ranges(line));
            },
            Mode::Ids => {
               
            },
        }
    }
 

   let mut total = 0;
   let merged = merge_ranges(ranges);

   for range in merged {
        total += (range.high +1) - range.low ;
   }


   println!("Total :{}", total)
}




fn merge_ranges(mut ranges: Vec<Ranges>) -> Vec<Ranges> {
    if ranges.is_empty() { 
        return vec![]; 
    }


    ranges.sort_by_key(|r| r.low);

    let mut merged = vec![ranges[0].clone()];

    for r in ranges.into_iter().skip(1) {
        let last = merged.last_mut().unwrap();

        if r.low <= last.high {
           
            last.high = last.high.max(r.high);
        } else {
            
            merged.push(r);
        }
    }

    merged
}

fn parse_ranges(line: &str) -> Ranges {
    let split: Vec<_> = line
    .split("-")
    .collect();

    if split.len() != 2 {
        panic!("[ERROR] Range is invalid");
    }

    let low = split
    .first()
    .unwrap()
    .parse::<i64>()
    .unwrap();

    let high = split
    .last()
    .unwrap()
    .parse::<i64>()
    .unwrap();

    Ranges::new(low, high)
}


/*

    10 - 20

    6 -  15

*/