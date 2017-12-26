import sys

def fix(s):
    return s.replace("Begin in state A.", "A") \
        .replace("Perform a diagnostic checksum after 12425180 steps.", "12425180") \
        .replace("If the current value is 0:", "0") \
        .replace("If the current value is 1:", "1") \
        .replace(":","") \
        .replace(".","") \
        .replace("In state ", "") \
        .replace("- ", "") \
        .replace("Write the value 1.", "1") \
        .replace("Write the value 0.", "0") \
        .replace("Move one slot to the right", "1") \
        .replace("Move one slot to the left", "-1") \
        .replace("Write the value ", "") \
        .replace("Continue with state ", "")


for line in sys.stdin.readlines():
    print fix(line.strip())

