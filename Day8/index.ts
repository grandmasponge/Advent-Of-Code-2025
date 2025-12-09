import * as fs from "node:fs"

const filename = "input.txt"

function distance(x: number, y: number, z: number, x2: number, y2: number, z2: number): number{
    return Math.sqrt(Math.pow((x2 - x), 2) + Math.pow((y2 - y), 2) + Math.pow((z2 - z), 2))
}

function find_circuits(positions: number[][]) {

 // i got part 1 then rage quit

}


async function main() {
    try {
        const data = fs.readFileSync(filename, {encoding: "utf-8"});
        const lines = data.split("\n");
        let positions: number[][] = []

        lines.forEach((line) => {
            let xyz: number[] = [];
            line.split(",").forEach((num) => {
                xyz.push(parseInt(num));
            })
            positions.push(xyz);
            
        })

        find_circuits(positions);


    } catch (err) {
    console.error(err);
  }

}


main()