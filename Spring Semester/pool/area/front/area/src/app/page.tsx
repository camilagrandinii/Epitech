"use client";
import React, { useEffect, useState } from 'react';
import { ThemeProvider, useTheme } from '../../context/DarkMode';
import { ThemeHandicap, useHandicap } from '../../context/Accessibility';
import './globals.css';
import './home.css';
import Sidebar from "./sidebar";

const HomePageContent = () => {
  const { isDarkMode, toggleTheme } = useTheme();
  const { isHandicapMode, toggleThemehandicap } = useHandicap();
  const [workflowPercentage, setWorkflowPercentage] = useState(0);
  const [inactiveWorkflowPercentage, setInactiveWorkflowPercentage] = useState(0);
  const [workflowName, setWorkflowName] = useState('');
  const [totalWorkflowPercentage, setTotalWorkflowPercentage] = useState(0);
  const [connectedServicePercentage, setConnectedServicePercentage] = useState(0);

  useEffect(() => {
    const fetchWorkflows = async () => {
      try {
        console.log("Fetching workflows from API...");
        const response = await fetch('http://localhost:5000/api/Areas', {
          method: 'GET',
          headers: {
            'Content-Type': 'application/json',
            'Authorization': `Bearer ${localStorage.getItem('authToken')}`
          }
        });

        if (!response.ok) {
          throw new Error(`HTTP error! status: ${response.status}`);
        }

        const data = await response.json();

        const activeWorkflows = data.filter(workflow => workflow.state === 1);
        const activePercentage = (activeWorkflows.length / data.length) * 100;
        setWorkflowPercentage(Math.round(activePercentage));

        if (activeWorkflows.length > 0) {
          setWorkflowName(`Active Workflow`);
        } else {
          setWorkflowName('Aucun workflow actif');
        }

        const inactiveWorkflows = data.filter(workflow => workflow.state !== 1);
        const inactivePercentage = (inactiveWorkflows.length / data.length) * 100;
        setInactiveWorkflowPercentage(Math.round(inactivePercentage));

        const totalPercentage = data.length;
        setTotalWorkflowPercentage(totalPercentage);
      } catch (error) {
        console.error('Erreur lors de la récupération des workflows:', error);
      }
    };
    //
    const fetchConnectedServices = async () => {
      try {
        console.log("Fetching connected services from API...");
        const response = await fetch('http://localhost:5000/api/ServiceTable', {
          method: 'GET',
          headers: {
            'Content-Type': 'application/json',
            'Authorization': `Bearer ${localStorage.getItem('authToken')}`
          }
        });

        if (!response.ok) {
          throw new Error(`HTTP error! status: ${response.status}`);
        }

        const servicesData = await response.json();
        const totalServices = servicesData.length;
        const connectedServices = servicesData.filter(service => service.connected === true);
        const connectedCount = connectedServices.length;
        const connectedPercentage = (connectedCount / totalServices) * 100;
        setConnectedServicePercentage(Math.round(connectedPercentage));

      } catch (error) {
        console.error('Erreur lors de la récupération des services connectés:', error);
      }
    };
    //

    fetchWorkflows();
    fetchConnectedServices();
  }, []);

  const radius = 100;
  const strokeWidth = 22;
  const normalizedRadius = radius - strokeWidth * 0.5;
  const circumference = normalizedRadius * 2 * Math.PI;
  const activeOffset = circumference - (workflowPercentage / 100) * circumference;
  const inactiveOffset = circumference - (inactiveWorkflowPercentage / 100) * circumference;
  const connectedOffset = circumference - (connectedServicePercentage / 100) * circumference;

  return (
    <Sidebar>
        {/* button for dark mode */}
      <div className={`container flex items-start justify-end mt-6}`}>
        <button onClick={toggleTheme} className="btn btn-light mb-3 mr-4">
          Dark Mode
        </button>
      </div>
        {/* button for handicap mode*/}
      <div className={`container flex items-start justify-end mt-6`}>
        <button onClick={toggleThemehandicap} className="btn btn-light mb-3 mr-4">
          Accessibility Mode
        </button>
      </div>

      <div className="circle-wrapper" style={{ display: 'flex', justifyContent: 'space-around' }}>
        <div className="circle-container" style={{ position: 'relative', width: '400px', height: '400px' }}>
          <svg width="400" height="400">
            <circle
              stroke="#B4BBEA"
              fill="transparent"
              r={normalizedRadius}
              strokeWidth={strokeWidth}
              cx="200"
              cy="200"
            />
            <circle
              stroke="#757BC8"
              fill="transparent"
              r={normalizedRadius}
              strokeWidth={strokeWidth}
              cx="200"
              cy="200"
              strokeDasharray={`${circumference} ${circumference}`}
              strokeDashoffset={activeOffset}
              style={{ transition: 'stroke-dashoffset 0.5s ease-in-out', strokeLinecap: 'round' }}
            />
          </svg>
          <span className="percentage">{workflowPercentage}%</span>
          <div className="workflow-name">{workflowName}</div>
        </div>

        <div className="circle-container" style={{ position: 'relative', width: '400px', height: '400px' }}>
          <svg width="400" height="400">
            <circle
              stroke="#B4BBEA"
              fill="transparent"
              r={normalizedRadius}
              strokeWidth={strokeWidth}
              cx="200"
              cy="200"
            />
            <circle
              stroke="#757BC8"
              fill="transparent"
              r={normalizedRadius}
              strokeWidth={strokeWidth}
              cx="200"
              cy="200"
              strokeDasharray={`${circumference} ${circumference}`}
              strokeDashoffset={inactiveOffset}
              style={{ transition: 'stroke-dashoffset 0.5s ease-in-out', strokeLinecap: 'round' }}
            />
          </svg>
          <span className="percentage">{inactiveWorkflowPercentage}%</span>
          <div className="workflow-name">Inactive Workflows</div>
        </div>

        <div className="circle-container" style={{ position: 'relative', width: '400px', height: '400px' }}>
          <svg width="400" height="400">
            <circle
              stroke="#B4BBEA"
              fill="transparent"
              r={normalizedRadius}
              strokeWidth={strokeWidth}
              cx="200"
              cy="200"
            />
            <circle
              stroke="#757BC8"
              fill="transparent"
              r={normalizedRadius}
              strokeWidth={strokeWidth}
              cx="200"
              cy="200"
              strokeDasharray={`${circumference} ${circumference}`}
              strokeDashoffset={connectedOffset}
              style={{ transition: 'stroke-dashoffset 0.5s ease-in-out', strokeLinecap: 'round' }}
            />
          </svg>
          <span className="percentage">{connectedServicePercentage}%</span>
          <div className="workflow-name">Services Connected</div>
        </div>
      </div>
      <div className="total-workflows">
      <h2 style={{ fontSize: '3rem', fontWeight: 'bold', margin: '10px 0' }}>{totalWorkflowPercentage}</h2><br></br>
      <h2 className='total-work'>Nb Total of Workflows</h2>
    </div>
    </Sidebar>
  );
}

export default function HomePage() {
  return (
      <ThemeProvider>
        <ThemeHandicap>
        <HomePageContent />
      </ThemeHandicap>
    // </ThemeProvider>
  );
}