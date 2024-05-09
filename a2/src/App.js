import React, { useState, useEffect } from 'react';
import axios from 'axios';
import goldcup from './Component/goldcup.jpg'
import silvercup from './Component/silvercup.jpg'
import bronzecup from './Component/bronzecup.jpg'
import './styling.css'

const App = () => {
  const [teams, setTeams] = useState([]);
  const [selectedTeam, setSelectedTeam] = useState('');
  const [score, setScore] = useState('');
  
  useEffect(() => {
    generateTeams();
  }, []);

  const generateTeams = () => {
    axios.get('http://localhost:8080/getteams')
      .then(response => {
        const sortedTeams = response.data.sort((a, b) => b.Score - a.Score);
        setTeams(sortedTeams);
      })
      .catch(err => console.error('Error fetching data:', err));
  };

  const handleTeamSelect = (event) => {
    setSelectedTeam(event.target.value);
  };

  const handleScoreChange = (event) => {
    setScore(event.target.value);
  };

  const handleWin = () => {
    const newScore = parseInt(score) + parseInt(teams.find(team => team.TeamName === selectedTeam).Score);
    const newTotalGamesPlayed = parseInt(teams.find(team => team.TeamName === selectedTeam).TotalGamesPlayed) + 1;

    axios.put(`http://localhost:8080/updateScore/${selectedTeam}`, { score: newScore, totalgames: newTotalGamesPlayed })
      .then(response => {
        console.log('Score updated successfully:', response.data);
        generateTeams();
      })
      .catch(err => console.error('Error updating score:', err));
  };
  
  const handleLoss = () => {
    const currentScore = parseInt(teams.find(team => team.TeamName === selectedTeam).Score);
    const newScore = currentScore - parseInt(score);
    const newTotalGamesPlayed = parseInt(teams.find(team => team.TeamName === selectedTeam).TotalGamesPlayed) + 1;
    
    axios.put(`http://localhost:8080/updateScore/${selectedTeam}`, { score: newScore, totalgames: newTotalGamesPlayed })
      .then(response => {
        console.log('Score updated successfully:', response.data);
        generateTeams();
      })
      .catch(err => console.error('Error updating score:', err));
  };
  

  return (
    <div className='text-white bodyclass' >
      <div style={{width:'80%' , margin:'auto'}}>
        <h1>Teams Table</h1>
        <table className="table table-striped table-striped-custom">
          <thead className='text-white theadline'>
            <tr>
              <th scope="col">#</th>
              <th scope="col">Team Name</th>
              <th scope="col">Total Games Played</th>
              <th scope="col">Score</th>
            </tr>
          </thead>
          <tbody>
            {teams.map((team, index) => (
              <tr key={team.id} className={index % 2 === 0 ? '' : 'odd-row table-primary'}>
                <th scope="row">
                  {index === 0 ? (
                    <img src={goldcup} alt="Gold Cup" className="img-fluid" style={{ width: '20px', height: '20px' }} />
                  ) : index === 1 ? (
                    <img src={silvercup} alt="Silver Cup" className="img-fluid" style={{ width: '20px', height: '20px' }} />
                  ) : index === 2 ? (
                    <img src={bronzecup} alt="Bronze Cup" className="img-fluid" style={{ width: '20px', height: '20px' }} />
                  ) : (
                    index + 1
                  )}
                </th>

                <td>
                  <img src={require(`./Component/${team.ImageName}.jpg`)} alt="Avatar" className="img-fluid" style={{ width: '20px', height: '20px', marginRight: '8px', borderRadius: '50%' }} />{team.TeamName}</td>
                <td>{parseInt(team.TotalGamesPlayed)}</td>
                <td>{parseInt(team.Score) >= 0 ? `+${parseInt(team.Score)}` : parseInt(team.Score)}</td>
              </tr>
            ))}
          </tbody>
        </table>
      </div>
      <div className='mb-5 text-center'>
        <h3>LET'S UPDATE SCORE TO SEE THE UPDATED TABLE</h3>
        <div className="input-group mb-3 d-flex justify-content-center">
          <select className="custom-select w-50" id="inputGroupSelect02" value={selectedTeam} onChange={handleTeamSelect}>
            <option value="">Select Team</option>
            {teams.map((team) => (
              <option key={team.id} value={team.TeamName}>{team.TeamName}</option>
            ))}
          </select>
        </div>
        <div className="input-group mb-3 d-flex justify-content-center" style={{width:'20%' , margin:'auto'}}>
          <input type="number" placeholder='Enter Score' className="form-control w-50" aria-label="Score" value={score} onChange={handleScoreChange} />
        </div>
        <div className="mb-3 d-flex justify-content-center">
          <div className="mx-2">
            <button type="button" className="btn btn-info" onClick={handleWin}>WIN</button>
          </div>
          <div className="mx-2">
            <button type="button" className="btn btn-info" onClick={handleLoss}>LOSS</button>
          </div>
        </div>
        <div>
          <p>With every score update, the game count will increase by 1</p>
        </div>
      </div>
    </div>
  );
};

export default App;
