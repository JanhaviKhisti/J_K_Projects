
import streamlit as st
import pandas as pd
import joblib
#from aqi_calculation import calculate_aqi

st.set_page_config(page_title="Air Quality Dashboard", layout="wide")
st.title("🌍 Real-Time Air Quality Monitoring Dashboard")

# Load cleaned data & model
df = pd.read_csv("../Data/cleaned_data.csv")
model = joblib.load("../Code/model.pkl")

# Display latest AQI prediction
latest = df.iloc[-1]

# Create DataFrame with feature names to avoid warning
input_df = pd.DataFrame([{
    'PM2.5': latest['PM2.5'],
    'NO2': latest['NO2'],
    'CO': latest['CO'],
    'O3': latest['O3']
}])

# Predict AQI
predicted_aqi = model.predict(input_df)[0]

# Display predicted AQI
st.metric("Predicted AQI", f"{predicted_aqi:.2f}")

# Display alert based on AQI level
if predicted_aqi >= 300:
    st.error("-- Hazardous AQI detected! Avoid going outside.")
elif predicted_aqi >= 200:
    st.warning("-- Very Unhealthy AQI! Sensitive groups should avoid exposure.")
elif predicted_aqi >= 100:
    st.info("-- Moderate AQI. Consider limiting outdoor activity.")
else:
    st.success("-- Air quality is good. Enjoy your day!")

# Pollutant trends
st.subheader("📊 Pollutant Concentration Trends (Recent)")
st.line_chart(df[['PM2.5', 'NO2', 'CO', 'O3']].tail(100))

