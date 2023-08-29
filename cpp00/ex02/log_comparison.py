import re

# Read log files and split entries
def read_log_file(file_path):
    with open(file_path, 'r') as file:
        content = file.read()
    entries = content.split('\n')
    return entries

def remove_timestamp(entry):
    return re.sub(r'\[\d{8}_\d{6}\]\s*', '', entry)

# Compare two log files
def compare_log_files(file1, file2):
    entries1 = read_log_file(file1)
    entries2 = read_log_file(file2)

    for index, ( entry1, entry2 ) in enumerate(zip(entries1, entries2)):
        stripped_entry1 = remove_timestamp(entry1)
        stripped_entry2 = remove_timestamp(entry2)
        if not stripped_entry1 == stripped_entry2:
            print(f"Difference found in line {index + 1} for:\n{entry1}")
            return
    print(f"No differences found")

if __name__ == "__main__":
    file1_path = "out"
    file2_path = "19920104_091532.log"
    compare_log_files(file1_path, file2_path)
