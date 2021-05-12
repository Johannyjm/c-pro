#[allow(unused_imports)]
use proconio::{
    input, fastout,
    marker::{Chars, Bytes, Usize1}
};

#[fastout]
fn main() {
    input!{
        s: Chars
    }
    for c in s{
        if c == '.'{
            break;
        }
        else{
            print!("{}", c);
        }
    }
    print!("\n");
}
