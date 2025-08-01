
import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns

def plot_data(data_path):
    df = pd.read_csv(data_path)
    df['date'] = pd.to_datetime(df['date'])
    df.set_index('date', inplace=True)

    df[['PM2.5', 'NO2', 'CO', 'O3']].plot(figsize=(12, 6), title="Pollutants Over Time")
    plt.ylabel("Concentration")
    plt.show()

if __name__ == "__main__":
    plot_data("../Data/cleaned_data.csv")