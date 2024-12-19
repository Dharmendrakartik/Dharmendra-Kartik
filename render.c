# Exported from Render on 2024-09-14T21:36:33Z
services:
- type: web
  name: DHARMENDRA-BOT-SS
  runtime: node
  repo: https://github.com/sk7295/DHARMENDRA-BOT-SS
  plan: free
  region: oregon
  buildCommand: npm install ytdl-core fs-extra yt-search
  startCommand: 'npm start '
version: "1"
