#[macro_use]
extern crate dmoj;

fn main() {
    let n = scan!(usize);
    let karr = (0..n).map(|_| scan!(u64)).collect::<Vec<_>>();
    let mut stk = Vec::with_capacity(n);
    stk.push((0, 0));

    let mut sol = 0;
    for (i, ai) in karr.into_iter().chain([0]).enumerate() {
        /*println!("=============");
        println!("Ai = {ai}");
        println!("Stack = {stk:?}");
        println!("Sol = {sol}");*/

        let mut sml = i;
        while stk.len()>0 {
            let (l, top) = stk[stk.len() - 1];
            if top < ai {
                break;
            }
            // Calculate the rectangle
            let dist = i - l;
            //println!("Rect in range [{};{}] and height {} Popped", l + 1, i, top);
            sol = sol.max(dist as u64 * top);
            sml = l;

            let _ = stk.pop();
        }

        stk.push((sml, ai));
    }
    println!("{sol}");
}