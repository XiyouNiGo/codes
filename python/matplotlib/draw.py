import matplotlib.pyplot as plt


def read_float_file(file_path):
    try:
        with open(file_path, 'r') as file:
            data = [float(line.strip()) for line in file.readlines()]
        return data
    except FileNotFoundError:
        print("Error: File not found!")
    except ValueError:
        print("Error: The file contains non-float data!")
    except Exception as e:
        print(f"Error: An unknown error occurred: {e}")
    return None


def plot_data(data):
    if data is not None:
        plt.plot(data)
        plt.plot(2232, 1001.8, 's-', label='Square')
        plt.plot(11643, 1001.8, 's-', label='Square')
        plt.plot(11914, 999.8, 's-', label='Square')
        plt.ylabel('img/sec')
        plt.title('Impact of BGCP on Pytorch')
        plt.show()


if __name__ == "__main__":
    file_path = 'data.txt'
    data = read_float_file(file_path)
    plot_data(data)
    