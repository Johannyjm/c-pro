use proconio::{input, fastout};

#[fastout]
fn main() {
    input! {
        n: usize,
        a: [usize; n]
    }

    // let mut cnt: [usize; 200] = [0; 200];
    // let mut cnt = vec![0_usize; 200];
    let mut cnt = [0; 200];
    for e in a{
        cnt[e % 200] += 1;
    }

    let mut res: i64 = 0;
    for i in 0..200{
        res += cnt[i] * (cnt[i]-1) / 2;
    }

    println!("{}", res);
}