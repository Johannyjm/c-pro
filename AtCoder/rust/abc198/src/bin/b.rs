use proconio::{input, fastout};

fn isp(s: String) -> bool{
    let n = s.len();
    for i in 0..n{
        if s.chars().nth(i).unwrap() != s.chars().nth(n-i-1).unwrap(){
            return false;
        }
    }

    return true;
}

#[fastout]
fn main() {
    input!{
        mut s: String
    }

    s = s.chars().rev().collect::<String>();

    for _ in 0..10{
        if isp(s.clone()){
            println!("Yes");
           return;
        }
        s.push('0');
    }

    println!("No");
}
