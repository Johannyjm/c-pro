use proconio::{input, fastout};
use std::collections::BinaryHeap;
use std::cmp::Reverse;

#[fastout]
fn main() {
    input!{
        r: usize, 
        c: usize, 
        a: [[i32; c-1]; r], 
        b: [[i32; c]; r-1]
    }

    let (sy, sx) = (0, 0);
    let (gy, gx) = (r-1, c-1);

    let dy: [isize; 3] = [0, 0, 1];
    let dx: [isize; 3] = [1, -1, 0];

    const INF: i32 = 1001001001;
    let mut dist = vec![vec![INF; c]; r];
    dist[sy][sx] = 0;
    let mut pq = BinaryHeap::new();
    pq.push(Reverse((0, sy, sx)));
    
    while !pq.is_empty(){
        let now = pq.pop();
        let Reverse((_, y, x)) = now.unwrap();

        for dir in 0..3 {
            let ny = y + dy[dir];
            let nx = x + dx[dir];

            if ny<0 || ny>=r || nx<0 || nx>=c {
                continue;
            }

            let cost;
            if dir == 0 {
                cost = a[y][x];
            }
            else if dir == 1 {
                cost = a[ny][nx];
            }
            else {
                cost = b[y][x];
            };

            if dist[ny][nx] > dist[y][x] + cost{
                dist[ny][nx] = dist[y][x] + cost;
                pq.push(Reverse((dist[ny][nx], ny, nx)));
            }
        }

        for i in 1..y+1 {
            let ny = y - i;
            let nx = x;

            if ny<0 || ny>=r || nx<0 || nx >= c {
                continue;
            }
            let cost = (i+1) as i32;

            if dist[ny][nx] > dist[y][x] + cost {
                dist[ny][nx] = dist[y][x] + cost;
                pq.push(Reverse((dist[ny][nx], ny, nx)));
            }
        }
    }


    println!("{}", dist[gy][gx]);
}
