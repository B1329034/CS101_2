import React from 'react';
import ReactDOM from 'react-dom/client';
import './index.css';
import App from './App'; // 這行會引入上面的 App.js
import reportWebVitals from './reportWebVitals';

// 這是 React 18 的標準寫法
const root = ReactDOM.createRoot(document.getElementById('root'));
root.render(
  <React.StrictMode>
    <App /> 
  </React.StrictMode>
);

reportWebVitals();
