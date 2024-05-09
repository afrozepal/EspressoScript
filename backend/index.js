const express = require('express');
const connectDB = require('./db.js');
const cors = require('cors');
const teamsModel = require('./models/teams.js');

const app = express();
app.use(express.json());
app.use(cors());

connectDB();
app.get('/getteams', (req, res) => {
    teamsModel.find({})
        .then(recipes => res.json(recipes))
        .catch(err => res.json(err));
});

app.put('/updateScore/:teamName', async (req, res) => {
    const { teamName } = req.params;
    const { score, totalgames } = req.body; // Destructure totalgames from req.body
    console.log('New Total Games Played:', totalgames);
    try {
        const updatedTeam = await teamsModel.findOneAndUpdate(
            { TeamName: teamName },
            { $set: { Score: score, TotalGamesPlayed: totalgames } }, // Combine both $set operations
            { new: true }
        );

        if (!updatedTeam) {
            return res.status(404).json({ message: 'Team not found' });
        }

        return res.status(200).json({ message: 'Score updated successfully', team: updatedTeam });
    } catch (error) {
        console.error('Error updating score:', error);
        return res.status(500).json({ message: 'Internal server error' });
    }
});



const port = 8080;
app.listen(port, () => {
    console.log(`Server is running on ${port}`);
});
