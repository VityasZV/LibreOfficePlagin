import subprocess
import time



for i in range(3):
    for it in range(3):
        subprocess.check_call([f"../build/Genetic_Algorithm {i}  {it}"], shell=True)
        # time.sleep(1)