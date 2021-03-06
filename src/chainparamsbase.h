// Copyright (c) 2014-2018 The Bitcoin Core developers
// Copyright (c) 2019-2020 The NutuCoin developers 
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCOIN_CHAINPARAMSBASE_H
#define BITCOIN_CHAINPARAMSBASE_H

#include <memory>
#include <string>
#include <vector>

#define   P2P_DEFAULT_PORT                     49638
#define   RPC_DEFAULT_PORT                     49639

#define   TESTNET_RPC_DEFAULT_PORT             49640
#define   REGTEST_RPC_DEFAULT_PORT             49641

#define   MAX_BLOCK_REWARD_HEIGHT              10000000

#define   MAINNET_SWAPPING_NUMBER              4325000
#define   MAINNET_SWAPPING_HEIGHT              1

#define   TESTNET_SWAPPING_NUMBER              1000
#define   TESTNET_SWAPPING_HEIGHT              1

#define   BLOCK_REWARD                         6
#define   BLOCK_NUM_PER_YEAR                   210240
#define   TESTNET_BLOCK_NUM_PER_YEAR           10000

#define   GENESIS_REWARD                       (BLOCK_REWARD)
#define   PRUNE_AFTER_HEIGHT_SIZE              100000
#define   TESTNET_PRUNE_AFTER_HEIGHT_SIZE      1000

#define   NTU_ACTIVATION_TIME_MAINNET          1565434800
#define   NTU_ACTIVATION_TIME_TESTNET          1566258256

#define   NTU_PAST_BLOCK_NUM                   100

#define   NTU_MAX_PAST_BLOCK                   (NTU_PAST_BLOCK_NUM)
#define   NTU_MAX_PAST_BLOCK_TESTNET           (NTU_PAST_BLOCK_NUM)


#define   NTU_VALID_MINING_TIME_TESTNET        1572192600  // Sunday, October 27, 2019 4:10:00 PM (GMT+0)
#define   NTU_VALID_MINING_TIME_MAINNET        1572805800  // Sunday, November 03, 2019 6:30:00 PM (GMT+0)
#define   X16RV2_ACTIVATION_TIME               1571396400  // Friday, October 18, 2019 11:00:00 AM (GMT+0)

/**
 * CBaseChainParams defines the base parameters (shared between bitcoin-cli and bitcoind)
 * of a given instance of the Bitcoin system.
 */
class CBaseChainParams
{
public:
    /** BIP70 chain name strings (main, test or regtest) */
    static const std::string MAIN;
    static const std::string TESTNET;
    static const std::string REGTEST;

    const std::string& DataDir() const { return strDataDir; }
    int RPCPort() const { return nRPCPort; }

    CBaseChainParams() = delete;
    CBaseChainParams(const std::string& data_dir, int rpc_port) : nRPCPort(rpc_port), strDataDir(data_dir) {}

private:
    int nRPCPort;
    std::string strDataDir;
};

/**
 * Creates and returns a std::unique_ptr<CBaseChainParams> of the chosen chain.
 * @returns a CBaseChainParams* of the chosen chain.
 * @throws a std::runtime_error if the chain is not supported.
 */
std::unique_ptr<CBaseChainParams> CreateBaseChainParams(const std::string& chain);

/**
 *Set the arguments for chainparams
 */
void SetupChainParamsBaseOptions();

/**
 * Return the currently selected parameters. This won't change after app
 * startup, except for unit tests.
 */
const CBaseChainParams& BaseParams();

/** Sets the params returned by Params() to those for the given network. */
void SelectBaseParams(const std::string& chain);

#endif // BITCOIN_CHAINPARAMSBASE_H
