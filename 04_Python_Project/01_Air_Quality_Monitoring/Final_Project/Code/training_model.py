
import pandas as pd
from sklearn.ensemble import RandomForestRegressor
from sklearn.model_selection import train_test_split
from sklearn.metrics import mean_squared_error
import joblib

def train_model(data_path, model_path):
    df = pd.read_csv(data_path)

    df.rename(columns={
    'pm2_5': 'PM2.5',
    'no2': 'NO2',
    'co': 'CO',
    'o3': 'O3'
    }, inplace=True)

    features = ['PM2.5', 'NO2', 'CO', 'O3']
    X = df[features]
    y = df['AQI']

    X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

    model = RandomForestRegressor()
    model.fit(X_train, y_train)

    preds = model.predict(X_test)
    mse = mean_squared_error(y_test, preds)
    rmse = mse ** 0.5
    print("-- Model trained. RMSE:", round(rmse, 2))
    
    joblib.dump(model, model_path)
    print("-- Model saved to:", model_path)

if __name__ == "__main__":
    train_model("../Data/cleaned_data.csv", "../Code/model.pkl")
