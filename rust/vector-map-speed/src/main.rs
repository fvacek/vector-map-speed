use rand::distributions::Alphanumeric;
use rand::Rng;
use std::collections::{BTreeMap, HashMap};
use std::time::{Instant};

fn main() {
    let mut hit_cnt: usize = 0;
    for n in vec![10, 100, 1000, 10_000, 100_000] {
        println!("=========== string count: {} ============", n);
        let mut vector: Vec<String> = vec![];
        let mut tree_map: BTreeMap<String, ()> = BTreeMap::new();
        let mut hash_map: HashMap<String, ()> = HashMap::new();
        generate_keys(&mut vector, n);
        let mut keys = vector.clone();
        keys.sort();
        for s in &vector {
            tree_map.insert(s.clone(), ());
            hash_map.insert(s.clone(), ());
        }
        {
            let start = Instant::now();
            for s1 in &keys {
                if vector.iter().any(|s2| s1 == s2) {
                    hit_cnt += 1;
                }
            }
            let duration = start.elapsed();
            println!("Vector1 seek time elapsed:  {:?}", duration / n as u32);
        }
        {
            let start = Instant::now();
            for s1 in &keys {
                tree_map.get(s1);
            }
            let duration = start.elapsed();
            println!("BTreeMap seek time elapsed: {:?}", duration / n as u32);
        }
        {
            let start = Instant::now();
            for s1 in &keys {
                hash_map.get(s1);
            }
            let duration = start.elapsed();
            println!("HashMap seek time elapsed:  {:?}", duration / n as u32);
        }
    }
    println!("hit cnt: {}", hit_cnt);
}

fn generate_keys(vec: &mut Vec<String>, n: usize) {
    const KEY_LEN: usize = 32;
    for _ in 0 .. n {
        let s: String = rand::thread_rng()
            .sample_iter(&Alphanumeric)
            .take(KEY_LEN)
            .map(char::from)
            .collect();
        //println!("{}", s);
        vec.push(s);
    }
}