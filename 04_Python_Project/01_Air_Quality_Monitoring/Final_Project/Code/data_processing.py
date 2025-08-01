
import pandas as pd

def preprocess_data(input_path, output_path):
    df = pd.read_csv(input_path)

    # Rename columns
    df.rename(columns={
    'pm2_5': 'PM2.5',
    'no2': 'NO2',
    'co': 'CO',
    'o3': 'O3'
    }, inplace=True)

    # Make sure 'Date' column exists
    if 'date' not in df.columns:
        print("-- Error: Column 'date' not found in the dataset.")
        print("Available columns:", df.columns.tolist())
        return

    # Convert 'Date' column to datetime
    df['date'] = pd.to_datetime(df['date'], errors='coerce')

    # Drop rows with invalid or missing dates
    df = df.dropna(subset=['date'])

    # Drop duplicates & handle missing values
    df = df.drop_duplicates().dropna()

    # Convert timestamp
    df['date'] = pd.to_datetime(df['date'], errors='coerce')
    df = df.dropna(subset=['date'])

    # Compute AQI
    df['AQI'] = df.apply(lambda row: calculate_aqi(row['PM2.5'], row['NO2'], row['CO'], row['O3']), axis=1)

    # Save cleaned data
    df.to_csv(output_path, index=False)
    print("-- Cleaned data saved to:", output_path)
    print(df.columns)

def calculate_aqi(pm2_5, no2, co, o3):
    # Simplified logic based on weights
    aqi = max(pm2_5 * 0.5, no2 * 0.4, co * 0.3, o3 * 0.2)
    return round(aqi, 2)

if __name__ == "__main__":
    preprocess_data("../Data/delhi_aqi.csv", "../Data/cleaned_data.csv")

