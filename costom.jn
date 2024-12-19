module.exports = async ({ api }) => {
  const logger = require('./utils/log')
  const configCustom = {
    autoRestart: {
      status: true,
      time: 1, //40 minutes
      note: 'TO AVOID ISSUES, PLEASE ENABLE PERIODIC BOT RESTART'
    },
    accpetPending: {
      status: true,    
      time: 30, //30 minutes
      note: 'APPROVE PENDING MESSAGES AFTER A CERTAIN TIME'
    }
  }
  function autoRestart(config) {
    if(config.status) {
      setInterval(async () => {
        logger(`STARTING SYSTEM RESTART!`, "[ Auto Restart ]")
        process.exit(1)
      }, config.time * 60 * 1000)
    }
  }
  function accpetPending(config) {
    if(config.status) {
      setInterval(async () => {
          const list = [
              ...(await api.getThreadList(1, null, ['PENDING'])),
              ...(await api.getThreadList(1, null, ['OTHER']))
          ];
          if (list[0]) {    
              api.sendMessage('[ 𝗖𝗛𝗘𝗖𝗞 ] YOU HAVE BEEN APPROVED FOR THE QUEUE. (THIS IS AN AUTOMATED MESSAGE)', list[0].threadID);
          }
      }, config.time * 60 * 1000)
    }
  }
  autoRestart(configCustom.autoRestart)
  accpetPending(configCustom.accpetPending)
};
