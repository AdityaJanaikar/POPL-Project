use std::env;
use std::fs::{self, File};
use std::io::{self, Read, Write};

fn swap_adjacent_characters(s: &str) -> String {
    let mut swapped = String::from(s);

    let mut chars = swapped.chars().collect::<Vec<_>>();

    for i in (0..chars.len() - 1).step_by(2) {
        chars.swap(i, i + 1);
    }

    swapped.clear();
    swapped.extend(chars);

    swapped
}

fn xor_with_key(s: &str, key: &str) -> String {
    let mut result = String::new();

    let key_chars = key.chars().cycle();

    for (c, k) in s.chars().zip(key_chars) {
        result.push((c as u8 ^ k as u8) as char);
    }

    result
}

fn display_in_hex(s: &str) {
    for c in s.chars() {
        print!("{:02X}", c as u8);
    }
    println!();
}

fn get_key_from_user() -> String {
    let mut key = String::new();
    io::stdin().read_line(&mut key).expect("Failed to read line");
    key.trim().to_string()
}

fn encrypt(s: &str, key: &str) -> String {
    let swapped = swap_adjacent_characters(s);
    xor_with_key(&swapped, key)
}

fn decrypt(enc: &str, key: &str) -> String {
    let dec = xor_with_key(enc, key);
    swap_adjacent_characters(&dec)
}

fn read_file_content(filename: &str) -> io::Result<String> {
    let mut file = File::open(filename)?;
    let mut content = String::new();
    file.read_to_string(&mut content)?;
    Ok(content)
}

fn write_to_file(filename: &str, content: &str) -> io::Result<()> {
    let mut file = File::create(filename)?;
    file.write_all(content.as_bytes())?;
    Ok(())
}

fn main() {
    let args: Vec<String> = env::args().collect();

    if args.len() != 2 {
        eprintln!("Usage: {} <filename>", args[0]);
        std::process::exit(1);
    }

    let filename = &args[1];

    // Read the content of the file
    match read_file_content(filename) {
        Ok(file_content) => {
            println!("Read content from file: {}", file_content);

            print!("Enter the encryption key: \n");
            let key = get_key_from_user();

            // Encrypt the content
            let encrypted = encrypt(&file_content, &key);
            println!("Encrypted string (Hex): ");
            display_in_hex(&encrypted);

            // Write encrypted content to encrypt.txt
            match write_to_file("encrypt_rust.txt", &encrypted) {
                Ok(()) => println!("Content encrypted and written to encrypt.txt."),
                Err(err) => eprintln!("Error writing to encrypt_rust.txt: {}", err),
            }

            // Decrypt the content
            let decrypted = decrypt(&encrypted, &key);

            // Write decrypted content to decrypt.txt
            match write_to_file("decrypt_rust.txt", &decrypted) {
                Ok(()) => println!("Content decrypted and written to decrypt_rust.txt."),
                Err(err) => eprintln!("Error writing to decrypt.txt: {}", err),
            }
        }
        Err(err) => eprintln!("Error reading file: {}", err),
    }
}
