use proconio::{input, fastout, marker::Chars};

#[fastout]
fn main() {
    input!{
        h: i32, 
        w: i32, 
        mut y: i32, 
        mut x: i32,
        s: [Chars; h]
    }
    y -= 1;
    x -= 1;

    let mut res = 1;
    let dy: [i32; 4] = [0, 1, 0, -1];
    let dx: [i32; 4] = [1, 0, -1, 0];

    for dir in 0..4{

        let mut cy = y;
        let mut cx = x;
        loop {
            let ny = cy + dy[dir];
            let nx = cx + dx[dir];

            if ny<0 || ny>=h || nx<0 || nx>=w{
                break;
            }
            if s[ny as usize][nx as usize] == '#'{
                break;
            }
            // println!("{}{}->{}{}: {}", cy, cx, ny, nx, s[ny as usize][nx as usize]);
            res += 1;

            cy = ny;
            cx = nx;
        }
    }

    println!("{}", res);
    
}
